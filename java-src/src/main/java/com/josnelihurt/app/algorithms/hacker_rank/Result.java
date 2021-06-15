package com.josnelihurt.app.algorithms.hacker_rank;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Result {

    /*
     * Complete the 'getTotalX' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY a
     *  2. INTEGER_ARRAY b
     */

    public static int getTotalX(List<Integer> a, List<Integer> b) {
        List<Integer> ab = new ArrayList<Integer>(a);
        ab.addAll(b);
        List<Integer> result = new ArrayList<Integer>();
        int maxAB = Collections.max(ab);
        for ( int i = 1; i <= maxAB; i++){
            final int ii = i;
            if (a.stream().anyMatch(it -> ii % it != 0)) {
                continue;
            }
            if (b.stream().anyMatch(it ->  it % ii  != 0)) {
                continue;
            }
            result.add(ii);
        }
        return result.size();
    }   
}