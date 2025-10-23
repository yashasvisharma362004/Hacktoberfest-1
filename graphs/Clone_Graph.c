/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

void DFS(struct Node* node, struct Node* clone_node, struct Node** visited);

void DFS(struct Node* node, struct Node* clone_node, struct Node** visited) 
{
    visited[node->val] = clone_node;

    for (int i = 0; i < node->numNeighbors; i++) 
    {
        struct Node* neighbor = node->neighbors[i];

        if (visited[neighbor->val] == NULL) 
        {
            struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
            clone->val = neighbor->val;
            clone->numNeighbors = neighbor->numNeighbors;
            clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * neighbor->numNeighbors);

            clone_node->neighbors[i] = clone;

            DFS(neighbor, clone, visited);
        } 
        else 
        {
            clone_node->neighbors[i] = visited[neighbor->val];
        }
    }
}

struct Node* cloneGraph(struct Node* node) {
    if (node == NULL)
        return NULL;

    struct Node* clone_node = (struct Node*)malloc(sizeof(struct Node));
    clone_node->val = node->val;
    clone_node->numNeighbors = node->numNeighbors;
    clone_node->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    struct Node* visited[101] = {NULL};

    visited[node->val] = clone_node;

    DFS(node, clone_node, visited);

    return clone_node;
}
