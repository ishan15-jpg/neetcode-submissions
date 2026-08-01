class Node {
    private int val;
    private Node next;

    public Node(int val){
        this.val = val;
        this.next = null;
    }
}

class LinkedList {
    private Node head;
    private Node tail;
    private int length;

    public LinkedList() {
        this.head = this.tail = null;
        this.length = 0;
    }

    public int get(int index) {
        if(index >= this.length) return -1;
        Node temp = this.head;
        int i = 0;
        while(i++ < index) temp = temp.next;
        return temp.val;
    }

    public void insertHead(int val) {
        if(this.head == null){
            this.head = this.tail = new Node(val);
            ++this.length;
            return;
        }
        Node temp = this.head;
        this.head = new Node(val);
        this.head.next = temp;
        ++this.length;
    }

    public void insertTail(int val) {
        if(this.tail == null){
            this.head = this.tail = new Node(val);
            ++this.length;
            return;
        }
        this.tail.next = new Node(val);
        this.tail = this.tail.next;
        ++this.length;
    }

    public boolean remove(int index) {
        if(index >= this.length) return false;
        if(index == 0){
            Node temp = this.head;
            this.head = this.head.next;
            temp.next = null;
            --this.length;
            return true;
        }
        Node prev = null;
        Node curr = this.head;
        int i = 0;
        while(i++ < index){
            prev = curr;
            curr = curr.next;
        }
        prev.next = curr.next;
        curr.next = null;
        if(index == this.length - 1) this.tail = prev;
        --this.length;
        return true;
    }

    public ArrayList<Integer> getValues() {
        if(this.head == null) return new ArrayList<Integer>();
        ArrayList<Integer> values = new ArrayList<Integer>();
        Node temp = this.head;
        while(temp != null){
            values.add(temp.val);
            temp = temp.next;
        }
        return values;
    }
}
