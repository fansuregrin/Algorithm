package leetcode.p2;

/**
 * 两数相加。
 * <p>
 * 给你两个非空的链表，表示两个非负的整数。
 * 它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * <a href="https://leetcode.cn/problems/add-two-numbers/description">see here</a>
 * </p>
 */
public class Solution {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode head = null, tail = null;
        while (l1 != null || l2 != null || carry > 0) {
            int v1 = 0, v2 = 0;
            if (l1 != null) {
                v1 = l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                v2 = l2.val;
                l2 = l2.next;
            }
            int sum = carry + v1 + v2;
            carry = sum / 10;
            if (head == null) {
                head = new ListNode(sum % 10);
                tail = head;
            } else {
                tail.next = new ListNode(sum % 10);
                tail = tail.next;
            }
        }
        return head;
    }

    public static ListNode toLinkedList(int[] arr) {
        if (arr == null) return null;
        ListNode head = null, tail = null;
        for (int x: arr) {
            if (head == null) {
                head = new ListNode(x);
                tail = head;
            } else {
                tail.next = new ListNode(x);
                tail = tail.next;
            }
        }
        return head;
    }

    public static String listToString(ListNode head) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        ListNode cur = head;
        while (cur != null) {
            if (cur != head) {
                sb.append(", ");
            }
            sb.append(cur.val);
            cur = cur.next;
        }
        sb.append("]");
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        ListNode l1 = toLinkedList(new int[]{2, 4, 3});
        ListNode l2 = toLinkedList(new int[]{5, 6, 4});
        ListNode result = solution.addTwoNumbers(l1, l2);
        System.out.println(listToString(result));
    }
}
