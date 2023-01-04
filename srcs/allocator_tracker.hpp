/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_tracker.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsaada <dsaada@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:18:55 by dsaada            #+#    #+#             */
/*   Updated: 2023/01/04 12:23:19 by dsaada           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_TRACKER_HPP
# define ALLOCATOR_TRACKER_HPP

template <class T>
class track_allocator{
    public:
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef const T*                        const_pointer;
        typedef T&                              reference;
        typedef const T&                        const_reference;
        typedef std::size_t                     size_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::allocator<T>               std_alloc;
        typedef std::map<void*, size_type>      alloc_tracker_type;
        typedef std::set<void*>                 construct_tracker_type;
        
    public:
        track_allocator()                                           {}
        track_allocator(const track_allocator &)                    {}
        template <typename U>
        track_allocator(const track_allocator<U> &)                 {}
        ~track_allocator()                                          {}

        pointer         address(reference x) const                  { return (&x); }
        const_pointer   address(const_reference x)                  { return (&x); }
        pointer         allocate(size_type n, const void* hint = 0) {
            pointer ptr = std_alloc().allocate(n, hint);
            track_allocate((void*)ptr, n);
            return (ptr);
        }
        void            deallocate(pointer ptr, size_type n)        {
            //a completer 
            if (ptr == NULL)
                std::cout << "Tried to deallocate null pointer" << std::endl;
            std_alloc().deallocate(ptr, n);
        }
        size_type       max_size() const                            { return (std_alloc().max_size()); }
        void            construct(pointer ptr, const_reference val) {
            if (ptr == NULL)
                std::cout << "Tried to construct on null pointer" << std::endl;
            if (track_construct((void*)p) == false)
                std::cout << "Tried to construct on initialized memory" << std::endl;
            std_alloc().construct(ptr, val);
        }
        void            destroy(pointer ptr)                        {
            if (ptr == NULL)
                std::cout << "Tried to destroy on null pointer" << std::endl;
            if (track_destroy((void*)p) == false)
                std::cout << "Tried to destroy on uninitialized memory" << std::endl;
            std_alloc().destroy(ptr);
        }
    private:
        //----- Allocator tracker -----
        static std::size_t          allocs_count()                                  { return (allocs.size()); }
        static bool                 allocs_empty()                                  { return (allocs.empty()); }
        static void                 track_allocate(void* ptr, std::size_t size)     { allocs.insert(std::make_pair(ptr, size));}
        static void                 track_deallocate(void* ptr, std::size_t size)   {
            alloc_tracker_type::iterator it = allocs.find(ptr);
            if (it == allocs.end()){
                std::cout << "Tried to deallocate on uninitialized memory" << std::endl;
            }
            else if (it->second != size){
                std::cout << "Tried to deallocate on valid pointer with wrong size" << std::endl;
            }
            allocs.erase(it);
        }
        //----- Constructor tracker -----
        static std::size_t          constructs_count()                              { return (constructs.size()); }
        static bool                 constructs_empty()                              { return (constructs.empty()); } 
        static bool                 track_construct(void* ptr)                      { }
        static bool                 track_destroy(void* ptr)                        {}
        //----- 
        static alloc_tracker_type           allocs;
        static constrcut_tracker_type       constructs;     
};

#endif