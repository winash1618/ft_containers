# ft_containers [![mkaruvan's 42 ft_containers Score](https://badge42.vercel.app/api/v2/clbza7w7b00110fl7w15e2x3y/project/2909410)](https://github.com/JaeSeoKim/badge42)
In this project, you will implement a few container types of the C++ standard template library.
- Actual Status : Finished
- Result        : 125

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)
## Project Description:
- Implement the following containers and turn in the necessary <container>.hpp files with a Makefile:
	- vector: You don’t have to do the vector<bool> specialization.
	- map
	- stack
- It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included. You can pass this assignment without the stack (80/100).
- But if you want to do the bonus part, you have to implement the 3 mandatory containers: vector, map and stack.
- You also have to implement:
	- std::iterator_traits
	- std::reverse_iterator
	- std::enable_if
	- Yes, it is C++11 but you will be able to implement it in a C++98 manner.
	- This is asked so you can discover SFINAE.
	- std::is_integral
	- std::equal and/or std::lexicographical_compare
	- std::pair
	- std::make_pair
## Requirements:
- The namespace must be ft.
- Each inner data structure used in your containers must be logical and justified (this means using a simple array for map is not ok).
- You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function or variable must be justified.
- All the member functions, non-member functions and overloads of the standard containers are expected.
- You must follow the original naming. Take care of details.
- If the container has an iterator system, you must implement it.
- You must use std::allocator.
- For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
- Of course, for the implementation of std::map::value_compare, the keyword friend is allowed.
- You can use https://www.cplusplus.com/ and https://cppreference.com/ as references.
## Testing
- You must also provide tests, at least a main.cpp, for your defense. You have to go further than the main given as example!
- You must produce two binaries that run the same tests: one with your containers only, and the other one with the STL containers.
- Compare outputs and performance / timing (your containers can be up to 20 times slower).
- Test your containers with: ft::<container>.
- A main.cpp file is available to download on the intranet project page.
### testers:
- https://github.com/mli42/containers_test
- https://github.com/Mikastiv/ft_containers-terminator
### What's the advantage of using std::allocator instead of new in C++?
- https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c
### When should you use friend classes? 
- https://stackoverflow.com/questions/6718209/when-should-you-use-friend-classes

### Writing a custom iterator in modern C++
- https://www.internalpointers.com/post/writing-custom-iterators-modern-cpp
- https://stackoverflow.com/questions/148540/creating-my-own-iterat
- https://www.daniweb.com/programming/software-development/threads/76622/need-help-writing-my-own-reverse-iterator-class


### map reference
- https://programmer.ink/think/use-a-red-black-tree-to-encapsulate-set-and-map-at-the-same-time.html
- https://blog.csdn.net/weixin_45599288/article/details/122383732
- https://blog.csdn.net/Dawn_sf/article/details/78506299?spm=1001.2101.3001.6650.16&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-16-78506299-blog-122383732.pc_relevant_multi_platform_featuressortv2dupreplace&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7ERate-16-78506299-blog-122383732.pc_relevant_multi_platform_featuressortv2dupreplace&utm_relevant_index=17
- https://blog.csdn.net/weixin_45599288/article/details/122520861
- https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
- https://www.tenouk.com/Sitemap.html
- https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
- https://sd.blackball.lv/library/Introduction_to_Algorithms_Third_Edition_(2009).pdf
- https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474e
- https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
### Algorithms
- https://www.youtube.com/channel/UCDYPS1xn3IB_B5NyWIIsfow/playlists
- https://sites.google.com/site/marywootters/teaching
- https://web.stanford.edu/class/cs106x/index.html
- https://www.youtube.com/channel/UCJA7QhEAg51tdUQojlqL_9A/playlists
- https://www.youtube.com/c/JennyslecturesCSITNETJRF/playlists
