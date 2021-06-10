package bst

type BSTNode struct {
	key   int
	left  *BSTNode
	right *BSTNode
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
