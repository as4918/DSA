typedef struct {
    int *stack;
    int *minStack;
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));

    obj->stack = malloc(30000 * sizeof(int));
    obj->minStack = malloc(30000 * sizeof(int));
    obj->top = -1;

    return obj;
}

void minStackPush(MinStack* obj, int val) {
    obj->top++;

    obj->stack[obj->top] = val;

    if (obj->top == 0) {
        obj->minStack[obj->top] = val;
    }
    else if (val < obj->minStack[obj->top - 1]) {
        obj->minStack[obj->top] = val;
    }
    else {
        obj->minStack[obj->top] = obj->minStack[obj->top - 1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top--;
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->minStack[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj->minStack);
    free(obj);
}