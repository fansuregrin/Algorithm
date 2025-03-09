package leetcode.p146;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    public static void main(String[] args) {
        LRUCache cache = new LRUCache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        System.out.println(cache.get(1));
        cache.put(3, 3);
        System.out.println(cache.get(2));
        cache.put(4, 4);
        System.out.println(cache.get(1));
        System.out.println(cache.get(3));
        System.out.println(cache.get(4));
    }

    private static class Node {
        int key;
        int value;
        Node prev;
        Node next;
    }

    private final int capacity;
    private Map<Integer, Node> map = new HashMap<>();
    private Node head;
    private Node tail;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        Node node;
        if ((node = map.get(key)) == null) {
            return -1;
        }
        moveToHead(node);
        return node.value;
    }

    public void put(int key, int value) {
        Node node;
        if ((node = map.get(key)) != null) {
            node.value = value;
            moveToHead(node);
            return;
        }
        if (map.size() >= capacity) {
            node = tail.prev;
            map.remove(node.key);
            node.key = key;
            node.value = value;
            moveToHead(node);
        } else {
            node = new Node();
            node.key = key;
            node.value = value;
            addToHead(node);
        }
        map.put(key, node);
    }

    private void addToHead(Node node) {
        node.next = head.next;
        node.next.prev = node;
        node.prev = head;
        head.next = node;
    }

    private void moveToHead(Node node) {
        // detach from the list
        node.prev.next = node.next;
        node.next.prev = node.prev;
        node.prev = null;
        node.next = null;
        // add node to head
        addToHead(node);
    }
}
