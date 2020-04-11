/*
Min Stack
Solution
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/
class MinStack {
public:
    int tp=-1;
    int a[100000];
    public:
        

        MinStack() {
            tp = -1;
        }

        void push(int x) {
            tp =tp + 1;
            a[tp] = x;
        }

        void pop() {
            if(tp>=0)
            {
                a[tp] = 0;
                tp = tp -1;    
            }
        }

        int top() {
            return a[tp];
        }

        int getMin() {
            int mins = a[0];
            
            for(int i=0;i<=tp;i++)
            {
                if(mins>a[i])
                {
                    mins = a[i];
                }
            }
            return mins;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
