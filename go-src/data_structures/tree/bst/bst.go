package bst

import "github.com/shivamMg/ppds/tree"

type BSTNode struct {
	key   int
	left  *BSTNode
	right *BSTNode
}

func (n *BSTNode) Data() interface{} {
	return n.key
}

func (n *BSTNode) Children() []tree.Node {
	result := []tree.Node{}
	if n.left != nil {
		result = append(result, n.left)
	}
	if n.right != nil {
		result = append(result, n.right)
	}
	return result
}

func NewBSTNode(k int) *BSTNode {
	return &BSTNode{
		key:   k,
		left:  nil,
		right: nil,
	}
}

func Insert(root *BSTNode, key int) *BSTNode {
	if root == nil {
		return NewBSTNode(key)
	}

	if key > root.key {
		root.right = Insert(root.right, key)
	}

	if key < root.key {
		root.left = Insert(root.left, key)
	}

	// equal case
	return root
}
