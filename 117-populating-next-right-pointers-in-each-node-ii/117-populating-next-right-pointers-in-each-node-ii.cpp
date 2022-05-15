class Solution {
public:
    Node* connect(Node* root) 
    { 
        // just created a queue because we are going to follow level order traversal and push our root into that initially
        queue<Node*> q;
        if(root)
            q.push(root);
        
        // BFS(Level) Traversal
        while(!q.empty())
        {
            // extracting the current queue size and make a next pointer with value NULL
            // because we pushing the elments in our queue -> right then left (and right next will always be NULL)
            int size = q.size();
            Node* nxt = nullptr;
            
            // do the traversal over current queue size
            for(int i=0;i<size;i++)
            {
                // extractong the queue front and pop that from our queue
                auto top = q.front();
                q.pop();
                
                // now according to need assign top next NULL
                // and make current top as next for the left element
                top->next = nxt;
                nxt = top;
                
                // push left and right nodes if they are available
                if(top->right)
                    q.push(top->right);
                if(top->left)
                    q.push(top->left);
            }
        }
        return root;
    }
};