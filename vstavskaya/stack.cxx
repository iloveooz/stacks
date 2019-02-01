
	#include <iostream>
	#define NMAX 100
	
	// Стек можно реализовать в виде следующей структуры:
	struct Stack {
		float elem[NMAX];
		int top;
	};
	
	// Индекс элемента, находящегося в вершине стека, равен 0.
	void init(Stack *stk) {
		stk->top = 0;
	}
	
	// Помещение элемента в стек
	void push(Stack *stk, float f) {
		if (stk->top < NMAX) {
			stk->elem[stk->top] = f;
			stk->top++;
		} 
		else
		std::cout << "Стек полон, количество элементов:" << stk->top << '\n';
	}
	
	// Удаление элемента из стека
	float pop(Stack *stk) {
		float elem;
		if (stk->top > 0) {
			stk->top--;
			elem = stk->elem[stk->top];
			return elem;
		} 
		else {
			std::cout << "Стек пуст!" << '\n';
			return 0;
		}
	}	

	// Извлечение вершины стека
	float stkTop(Stack *stk) {
		if(stk->top > 0) {
			return stk->elem[stk->top - 1];
		} 
		else {
			std::cout << "Стек пуст!" << '\n';
			return 0;
		}
	}
	
	// Получение верхнего элемента стека без его удаления
	int gettop(Stack *stk) {
		return stk->top;
	}
	
	// Определение пустоты стека
	int isempty(Stack *stk) {
		if (stk->top == 0)
			return 1;
		else 
			return 0;
	}
	
	// Вывод элементов стека
	void stkPrint(Stack *stk) {
		int i = stk->top;
		if (isempty(stk) == 1) 
			return;
		do {
			i--;
			std::cout << stk->elem[i] << '\n';
		}
		while (i > 0);
	}
	
	int main() {
		Stack *stk;
		int i, n;
		float elem;
		
		stk = new Stack;
		init(stk);
		
		std::cout << "Введите количество элементов в стеке: ";
		std::cin >> n;
		
		for(i = 0; i < n; i++) {
			std::cout << "Введите " << i << "-й элемент: ";
			std::cin >> elem;
			
			push(stk, elem);
		}
		
		std::cout << "В стеке " << gettop(stk) << " элементов." << '\n';
				
		stkPrint(stk);
		
		std::cout << "Верхний элемент " << stkTop(stk) << '\n';
		do {
			std::cout << "Извлекаем элемент " << pop(stk);
			std::cout << ". В стеке осталось " << gettop(stk) << " элементов." << '\n';
		} 
		while (isempty(stk) == 0);
		
		std::cout << '\n';
		return 0;
	}
