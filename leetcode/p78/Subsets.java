package leetcode.p78;

import java.util.ArrayList;
import java.util.List;

/**
 * Subsets.
 * Given an integer array nums of unique elements,
 * return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets.
 * Return the solution in any order.
 * <a href="https://leetcode.cn/problems/subsets/description">see here</a>
 */
public class Subsets {
    private int n;

    public List<List<Integer>> subsets(int[] nums) {
        n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> set = new ArrayList<>();
        select(0, set, res, nums);
        return res;
    }

    private void select(int i, List<Integer> set, List<List<Integer>> res, int[] nums) {
        if (i == n) {
            res.add(new ArrayList<Integer>(set));
            return;
        }
        select(i+1, set, res, nums);
        set.add(nums[i]);
        select(i+1, set, res, nums);
        set.remove(set.size()-1);
    }

    public static void main(String[] args) {
        Subsets solution = new Subsets();
        int[] nums = {1, 2, 3};
        List<List<Integer>> result = solution.subsets(nums);
        System.out.println(result);
    }
}
