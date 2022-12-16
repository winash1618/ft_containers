/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaruvan <mkaruvan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:57:15 by mkaruvan          #+#    #+#             */
/*   Updated: 2022/12/15 19:51:21 by mkaruvan         ###   ########.fr       */
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
		while (current_node->_left != nil)
			current_node = current_node->_left;
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
}
#endif