package ds.linked_list;

/**
 * Single Linked List
 */
public class LinkedList<T> {

    private ListNode<T> head;
    private ListNode<T> tail;

    public LinkedList() {}

    public void push(T value) {
        ListNode<T> node = new ListNode<>(value);
        if (head == null) {
            head = node;
        } else {
            tail.next = node;
        }
        tail = node;
    }

    public void pop() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }
        head = head.next;
    }

    public ListNode<T> front() {
        if (head == null) {
            throw new IllegalStateException("List is empty");
        }
        return head;
    }

    public static class ListNode<T> {
        T value;
        ListNode<T> next;
        ListNode() {}
        ListNode(T value) { this.value = value; }
        ListNode(T value, ListNode<T> next) {
            this.value = value;
            this.next = next;
        }

        @Override
        public String toString() {
            return value.toString();
        }
    }

    @Override
    public String toString() {
        ListNode<T> cur = head;
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        while (cur != null) {
            if (cur != head) {
                sb.append(", ");
            }
            sb.append(cur.toString());
            cur = cur.next;
        }
        sb.append("]");
        return sb.toString();
    }

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        System.out.println(list);
        list.push(1);
        list.push(2);
        list.push(3);
        System.out.println(list);
        list.pop();
        System.out.println(list);
        System.out.println(list.front());
    }

}
