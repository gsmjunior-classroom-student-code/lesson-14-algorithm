#include <stdio.h>

// 노드 구조체 정의
typedef struct Node {
    char data; // 노드의 이름
    struct Node *left; // 왼쪽 자식 노드
    struct Node *right; // 오른쪽 자식 노드
} Node;

// 노드 생성 함수
Node *createNode(char data) {
    Node *node = (Node *)malloc(sizeof(Node)); // 메모리 할당
    node->data = data; // 노드의 이름 저장
    node->left = NULL; // 왼쪽 자식 노드 초기화
    node->right = NULL; // 오른쪽 자식 노드 초기화
    return node; // 노드 반환
}

// 전위 순회 함수
void preorder(Node *root) {
    if (root == NULL) return; // 루트 노드가 NULL이면 종료
    printf("%c", root->data); // 루트 노드의 이름 출력
    preorder(root->left); // 왼쪽 자식 노드를 루트로 하는 서브트리 전위 순회
    preorder(root->right); // 오른쪽 자식 노드를 루트로 하는 서브트리 전위 순회
}

// 중위 순회 함수
void inorder(Node *root) {
    if (root == NULL) return; // 루트 노드가 NULL이면 종료
    inorder(root->left); // 왼쪽 자식 노드를 루트로 하는 서브트리 중위 순회
    printf("%c", root->data); // 루트 노드의 이름 출력
    inorder(root->right); // 오른쪽 자식 노드를 루트로 하는 서브트리 중위 순회
}

// 후위 순회 함수
void postorder(Node *root) {
    if (root == NULL) return; // 루트 노드가 NULL이면 종료
    postorder(root->left); // 왼쪽 자식 노드를 루트로 하는 서브트리 후위 순회
    postorder(root->right); // 오른쪽 자식 노드를 루트로 하는 서브트리 후위 순회
    printf("%c", root->data); // 루트 노드의 이름 출력
}

// 메인 함수
int main() {
    int N; // 노드의 개수
    scanf("%d", &N); // 노드의 개수 입력받기
    Node *tree[26]; // 노드 배열 선언
    for (int i = 0; i < 26; i++) {
        tree[i] = NULL; // 노드 배열 초기화
    }
    for (int i = 0; i < N; i++) {
        char parent, left, right; // 부모 노드, 왼쪽 자식 노드, 오른쪽 자식 노드의 이름
        scanf(" %c %c %c", &parent, &left, &right); // 공백을 무시하고 이름 입력받기
        if (tree[parent - 'A'] == NULL) { // 부모 노드가 아직 생성되지 않았다면
            tree[parent - 'A'] = createNode(parent); // 부모 노드 생성
        }
        if (left != '.') { // 왼쪽 자식 노드가 존재한다면
            tree[left - 'A'] = createNode(left); // 왼쪽 자식 노드 생성
            tree[parent - 'A']->left = tree[left - 'A']; // 부모 노드의 왼쪽 자식 노드로 연결
        }
        if (right != '.') { // 오른쪽 자식 노드가 존재한다면
            tree[right - 'A'] = createNode(right); // 오른쪽 자식 노드 생성
            tree[parent - 'A']->right = tree[right - 'A']; // 부모 노드의 오른쪽 자식 노드로 연결
        }
    }
    preorder(tree[0]); // A를 루트로 하는 트리 전위 순회
    printf("\n"); // 줄바꿈
    inorder(tree[0]); // A를 루트로 하는 트리 중위 순회
    printf("\n"); // 줄바꿈
    postorder(tree[0]); // A를 루트로 하는 트리 후위 순회
    printf("\n"); // 줄바꿈
    return 0; // 프로그램 종료
}
