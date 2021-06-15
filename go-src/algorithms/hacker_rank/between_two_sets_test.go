package hacker_rank

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestGetTotalXCase0(t *testing.T) {
	a := []int32{2, 6}
	b := []int32{24, 36}
	result := getTotalX(a, b)
	assert.Equal(t, int32(2), result)
}
func TestGetTotalXCase8(t *testing.T) {
	a := []int32{3, 4}
	b := []int32{24, 48}
	result := getTotalX(a, b)
	assert.Equal(t, int32(2), result)
}
func TestGetTotalXCase4(t *testing.T) {
	a := []int32{1}
	b := []int32{100}
	result := getTotalX(a, b)
	assert.Equal(t, int32(9), result)
}
