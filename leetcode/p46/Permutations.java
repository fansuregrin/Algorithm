package leetcode.p46;

import java.util.ArrayList;
import java.util.List;

public class Permutations {
    public static void main(String[] args) {
        Permutations p = new Permutations();
        int[] nums = {1, 2, 3};
        List<List<Integer>> res = p.permute(nums);
        for (List<Integer> list : res) {
            System.out.println(list);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        int len = nums.length;
        List<Integer> nums2 = new ArrayList<>(len);
        for (int num : nums) {
            nums2.add(num);
        }
        List<List<Integer>> res = new ArrayList<>();
        solve(nums2, 0, res);
        return res;
    }

    private static <T> void swap(List<T> list, int x, int y) {
        // check index
        int len = list.size();
        if (x < 0 || x >= len || y < 0 || y >= len) {
            throw new IndexOutOfBoundsException("x=" + x + ", y=" + y + ", len=" + len);
        }

        T t = list.get(x);
        list.set(x, list.get(y));
        list.set(y, t);
    }

    private static void solve(List<Integer> nums, int start, List<List<Integer>> res) {
        if (start == nums.size()) {
            res.add(new ArrayList<>(nums));
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums, start, i);
            solve(nums, start + 1, res);
            swap(nums, start, i);
        }
    }
}
