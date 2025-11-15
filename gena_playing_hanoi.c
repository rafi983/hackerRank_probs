#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DISKS 10
#define NUM_RODS 4
#define MAX_STATES 1048576

typedef struct {
    int state[MAX_DISKS];
} State;

typedef struct {
    State state;
    int moves;
} QueueNode;

int n;
int visited[MAX_STATES];

int encode_state(int state[]) {
    int encoded = 0;
    for (int i = 0; i < n; i++) {
        encoded = encoded * NUM_RODS + (state[i] - 1);
    }
    return encoded;
}

bool is_goal(int state[]) {
    for (int i = 0; i < n; i++) {
        if (state[i] != 1) {
            return false;
        }
    }
    return true;
}

int get_top_disk(int state[], int rod) {
    for (int i = 0; i < n; i++) {
        if (state[i] == rod) {
            return i;
        }
    }
    return -1;
}

bool can_move(int state[], int from, int to) {
    int disk_from = get_top_disk(state, from);
    if (disk_from == -1) {
        return false;
    }

    int disk_to = get_top_disk(state, to);
    if (disk_to == -1) {
        return true;
    }

    return disk_from < disk_to;
}

int bfs(int initial_state[]) {
    QueueNode* queue = (QueueNode*)malloc(MAX_STATES * sizeof(QueueNode));
    int front = 0, rear = 0;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        queue[rear].state.state[i] = initial_state[i];
    }
    queue[rear].moves = 0;
    rear++;

    int encoded = encode_state(initial_state);
    visited[encoded] = 1;

    while (front < rear) {
        QueueNode current = queue[front++];

        if (is_goal(current.state.state)) {
            return current.moves;
        }

        for (int from = 1; from <= NUM_RODS; from++) {
            for (int to = 1; to <= NUM_RODS; to++) {
                if (from == to) {
                    continue;
                }

                if (can_move(current.state.state, from, to)) {
                    int new_state[MAX_DISKS];
                    for (int i = 0; i < n; i++) {
                        new_state[i] = current.state.state[i];
                    }

                    int disk = get_top_disk(new_state, from);
                    new_state[disk] = to;

                    int new_encoded = encode_state(new_state);

                    if (!visited[new_encoded]) {
                        visited[new_encoded] = 1;

                        for (int i = 0; i < n; i++) {
                            queue[rear].state.state[i] = new_state[i];
                        }
                        queue[rear].moves = current.moves + 1;
                        rear++;
                    }
                }
            }
        }
    }

    return -1;
}

int hanoi(int posts_count, int* posts) {
    n = posts_count;
    return bfs(posts);
}

int main() {
    int posts_count;
    scanf("%d", &posts_count);

    int* posts = (int*)malloc(posts_count * sizeof(int));
    for (int i = 0; i < posts_count; i++) {
        scanf("%d", &posts[i]);
    }

    int result = hanoi(posts_count, posts);
    printf("%d\n", result);

    return 0;
}

