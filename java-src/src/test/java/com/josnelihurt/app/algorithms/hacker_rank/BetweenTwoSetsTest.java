package com.josnelihurt.app.algorithms.hacker_rank;
import java.util.Arrays;
import java.util.List;

import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class BetweenTwoSetsTest 
{
	@Test
	public void TestGetTotalXCase0() {
		List<Integer> a = Arrays.asList(2, 6);
		List<Integer> b = Arrays.asList(24, 36);
		int result = Result.getTotalX(a, b);
		assert result == 2;
	}

	@Test
	public void TestGetTotalXCase8() {
		List<Integer> a = Arrays.asList(3, 4);
		List<Integer> b = Arrays.asList(24, 48);
		int result = Result.getTotalX(a, b);
		assert result == 2;
	}

	@Test
	public void TestGetTotalXCase4() {
		List<Integer> a = Arrays.asList(1);
		List<Integer> b = Arrays.asList(100);
		int result = Result.getTotalX(a, b);
		assert result == 9;
	}
}