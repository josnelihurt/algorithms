package bst

import (
	"math/rand"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestNewBSTNode(t *testing.T) {
	aRandomNumber := rand.Int()
	node := NewBSTNode(aRandomNumber)
	assert.NotNil(t, node)
	assert.Equal(t, aRandomNumber, node.key)
	assert.Nil(t, node.left)
	assert.Nil(t, node.right)
}

func TestInsertBSTNode(t *testing.T) {

	aRandomNumber := rand.Int()
	tcs := []struct {
		name         string
		root         *BSTNode
		inputKey     int
		expectedRoot *BSTNode
	}{
		{
			name:     "insert to the left",
			root:     NewBSTNode(aRandomNumber),
			inputKey: aRandomNumber - 1,
			expectedRoot: &BSTNode{
				key:  aRandomNumber,
				left: NewBSTNode(aRandomNumber - 1),
			},
		},
		{
			name:     "insert to the right",
			root:     NewBSTNode(aRandomNumber),
			inputKey: aRandomNumber + 1,
			expectedRoot: &BSTNode{
				key:   aRandomNumber,
				right: NewBSTNode(aRandomNumber + 1),
			},
		},
		{
			name: "same value inserted",
			root: &BSTNode{
				key: aRandomNumber,
			},
			inputKey:     aRandomNumber,
			expectedRoot: NewBSTNode(aRandomNumber),
		},
		{
			name:         "nil root",
			root:         nil,
			inputKey:     aRandomNumber,
			expectedRoot: NewBSTNode(aRandomNumber),
		},
		{
			name:         "default",
			expectedRoot: &BSTNode{},
		},
	}

	for _, tc := range tcs {
		t.Run(tc.name, func(t *testing.T) {
			//Prepare

			//Act
			root := Insert(tc.root, tc.inputKey)

			//Assert
			assert.Equal(t, tc.expectedRoot, root)

		})
	}
}
