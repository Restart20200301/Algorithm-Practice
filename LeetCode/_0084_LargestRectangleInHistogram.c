/**
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

 #define MAX(a, b) \
    (a) > (b) ? (a) : (b)

typedef struct Stack {
	int top;
	int a[0];
} Stack;

Stack* createStack(int cap) {
	Stack* s = (Stack*)malloc(sizeof(Stack) + cap * sizeof(int));
	s->top = -1;
	return s;
}

void releaseStack(Stack* s) {
	free(s);
}

void push(Stack* s, int val) {
	(s->a)[++(s->top)] = val;
}

int pop(Stack* s) {
	return (s->a)[(s->top)--];
}

int top(Stack* s) {
	return (s->a)[s->top];
}

int largestRectangleArea(int* heights, int heightsSize) {
	int* newHights = malloc(sizeof(int) * (heightsSize + 2));
	memset(newHights, 0, sizeof(int) * (heightsSize + 2));
	for (int i = 1; i < heightsSize + 1; i++) {
		newHights[i] = heights[i - 1];
	}
	Stack* s = createStack(heightsSize + 2);
	push(s, 0);
	int area = 0;
	for (int i = 1; i < heightsSize + 2; i++) {
		while (newHights[top(s)] > newHights[i]) {
			int height = newHights[pop(s)]; // 不要函数直接放到MAX去
			int width = i - top(s) - 1;
			area = MAX(area, width * height);
		}
		push(s, i);
	}
	free(newHights);
	releaseStack(s);
	return area;
}