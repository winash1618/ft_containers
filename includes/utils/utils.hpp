/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/14 07:57:16 by mkaruvan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
namespace ft
{
	enum color_t { BLACK, RED };

	template<class T>
	struct RBTreeNode
	{
		RBTreeNode<T>* _left;
		RBTreeNode<T>* _right;
		RBTreeNode<T>* _parent;
		
		T _data;
		color_t _color;
		RBTreeNode(const T& data) : _left(), _right(), _parent(), _data(data), _color(RED) {}
		RBTreeNode() : _left(), _right(), _parent(), _data(), _color(RED) {}
	};

	template <class _NodePtr>
	inline
	bool
	tree_is_left_child(_NodePtr current_node, _NodePtr nil)
	{
		if (current_node != nil )
			if (current_node->_parent != nil)
				return current_node == current_node->_parent->_left;
		return 0;
	}

	template <class _NodePtr>
	inline
	_NodePtr
	tree_min(_NodePtr current_node, _NodePtr nil)
	{
		// std::cout << "tree_min" << current_node->_data.first << std::endl;
		// try
		// {
		// 	if (current_node != nil)
		// 		throw std::exception();
		// }
		// catch(const std::exception& e)
		// {
		// 	std::cerr << e.what() << '\n';
		// 	exit(1);
		// }
		
		while (current_node->_left != nil)
		{
			// std::cout << "current_node: " << current_node << std::endl;
			current_node = current_node->_left;
		}
		return current_node;
	}

	template <class _NodePtr>
	inline
	_NodePtr
	tree_max(_NodePtr current_node, _NodePtr nil)
	{
		while (current_node->_right != nil)
			current_node = current_node->_right;
		return current_node;
	}

	// template <class _NodePtr>
	// _NodePtr
	// tree_next(_NodePtr current_node)
	// {
	// 	if (current_node->_right != nil)
	// 		return tree_min(current_node->_right);
	// 	while (!tree_is_left_child(current_node) && current_node->_parent)
	// 	{
	// 		current_node = current_node->_parent;
	// 	}
	// 	return current_node->_parent;
	// }

	// template <class _NodePtr>
	// _NodePtr
	// tree_prev(_NodePtr current_node)
	// {
	// 	if (current_node == nil)
	// 		return  nil;
	// 	if (current_node->_left != nil)
	// 		return tree_max(current_node->_left);
	// 	while (tree_is_left_child(current_node))
	// 		current_node = current_node->_parent;
	// 	return current_node->_parent;
	// }
}
#endif