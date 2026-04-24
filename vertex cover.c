 #include <stdio.h>
 #define V 5 // Number of vertices in our graph
 /* A simple greedy approach to find a Vertex Cover.
 * It follows a 2-approximation strategy.
 */
void findVertexCover(int graph[V][V])
 {
 int visited[V]; // Array to represent our Cover Set 'C'
 // Start with an empty set C by marking all vertices as "unmarked = 0"
 for (int i = 0; i < V; i++)
 {
visited[i] = 0;
 }
 // Repeat until no unmarked edges remain in C (visited array)
 // We use nested loops to scan every possible edge (u, v) in the matrix.
 for (int u = 0; u < V; u++)
 {
 for (int v = 0; v < V; v++)
 {
 // graph[u][v] == 1 --> Edge Exists
 // !visited[u] && !visited[v] --> Both endpoints are unmarked.
 if (graph[u][v] == 1 && !visited[u] && !visited[v])
 {
 // Add BOTH its endpoints to cover set C
 visited[u] = 1;
visited[v] = 1;
 /* Removing of all edges incident on those two vertices
 We don't need to code to delete the edges. 
34. By marking 'u' and 'v' as visited, 
35. our 'if' condition above will automatically skip all other edges 
connected to them! */
 }
 }
 }
 // Return the Cover Set C by printing all vertices we marked
 printf("Approximate Vertex Cover: ");
 int count = 0;
 for (int i = 0; i < V; i++)
 {
 if (visited[i])
 {
 printf("%d ", i);
 count++;
 }
 }
 printf("\nTotal vertices in the cover: %d\n", count);
 }
int main()
 {
 // Adjacency Matrix representation (1 = Edge exists, 0 = No edge)
 int graph[V][V] = {
 {0, 1, 0, 0, 0},
 {1, 0, 1, 1, 0},
 {0, 1, 0, 1, 1},
 {0, 1, 1, 0, 1},
 {0, 0, 1, 1, 0}};
 printf("Executing Vertex Cover Approximation...\n");
 findVertexCover(graph);
 return 0;
 }
