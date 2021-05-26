import java.util.*;

class Node
{
    int value;
    Node left;
    Node right;
    
    public Node(int v)
    {
        value = v;
        left = right = null;
    }
}

public class BST {

    Node root;

    BST()
    {
        root = null;
    }

    private Node add_item(Node root, int v)
    {
        if (root == null)
            return new Node(v);
        else if (v < root.value)
            root.left = add_item(root.left, v);
        else
            root.right = add_item(root.right, v);
        
        return root;
    }

    public void add_item(int v)
    {
        root = add_item(root, v);
    }

    private void search_item(Node root, int v)
    {
        if (root == null) {
            System.out.println("Tree is empty: No Item found");
            return;
        }

        if (v == root.value) {
            System.out.println("Item found");
            return;
        }

        if (v < root.value)
            search_item(root.left, v);
        else
            search_item(root.right, v);
    }

    public void search_item(int v)
    {
        search_item(root, v);
    }

    private void in_order_traversal(Node root)
    {
        if (root == null)
            return;
        in_order_traversal(root.left);
        System.out.println("Element is : " + root.value);
        in_order_traversal(root.right);
    }

    public void in_order_traversal()
    {
        in_order_traversal(root);    
    }

    
    private void print_paths(Node root, Stack<Integer> st, Integer max_path_sum)
    {
        if (root == null) return;

        st.push(root.value);

        if (root.left == null && root.right == null){
            Iterator itr = st.iterator();
            int curent_path_sum = 0;
            while (itr.hasNext())
            {
                int value = itr.next();
                System.out.println(value); 
                curent_path_sum += value;
            }
            
            if (curent_path_sum > max_path_sum)
                max_path_sum = curent_path_sum;

            st.pop();
            return;   
        }

        print_paths(root.left, st, max_path_sum);
        print_paths(root.right, st, max_path_sum);

        st.pop();
    }
    
    public void print_paths()
    {
        Stack<Integer> st = new Stack<Integer>();
        Vector<Stack> paths = new Vector<Stack>();
        Integer max_path_sum = new Integer();
        max_path_sum = 0;
        print_paths(root, st, max_path_sum);          
        System.out.println("Max Path length " + max_path_sum);
    }
    
    /*
    private level_order_traversal(Node root)
    {
        //
    }

    public level_order_traversal()
    {
        level_order_traversal(root);
    }

    public Node get_node(int v)
    {
        //Returns node corresponding to a value
        return null;
    }
    
    void get_diameter()
    {
        //Return type
    }

    Node get_lca(Node n1, node n2)
    {

    }
    */

    public static void main(String args[])
    {
        BST bst = new BST();
        bst.add_item(5);
        bst.add_item(1);
        bst.add_item(2);
        bst.add_item(4);
        bst.add_item(8);
        bst.add_item(9);

        bst.in_order_traversal();
        bst.print_paths();
    }  
}
