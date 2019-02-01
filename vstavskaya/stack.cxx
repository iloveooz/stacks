
	#include <iostream>
	#define NMAX 10
	
	// Стек можно реализовать в виде следующей структуры:
	struct Stack {
		int top;
		double *elem;
		
		// конструктор
		Stack(int N) {
			top = 0;		
			elem = new double[N];
			std::cout << "Стэк создан." << '\n';
		}
		
		~Stack() {
			// delete [] elem;
			delete elem;
			std::cout << "Стэк уничтожен." << '\n';
		}

		// Индекс элемента, находящегося в вершине стека, равен 0.
		void init() {
			top = 0;
		}
				
		// Помещение элемента в стек
		void push(double f) {
			if (top < NMAX) {
				elem[top] = f;
				top++;
			} 
			else
			std::cout << "Стек полон, количество элементов: " << top << '\n';
		}
				
		// Удаление элемента из стека
		double pop() {
			double element;
			if (top > 0) {
				top--;
				element = elem[top];
				return element;
			} 
			else {
				std::cout << "Стек пуст!" << '\n';
				return 0;
			}
		}	

		// Извлечение вершины стека
		double stkTop() {
			if(top > 0) {
				return elem[top - 1];
			} 
			else {
				std::cout << "Стек пуст!" << '\n';
				return 0;
			}
		}
		
		// Получение верхнего элемента стека без его удаления
		int gettop() {
			return top;
		}
		
		// Определение пустоты стека
		int isempty() {
			if (top == 0)
				return 1;
			else 
				return 0;
		}
		
		// Вывод элементов стека
		void stkPrint() {
			int i = top;
			if (isempty() == 1) 
				return;
			do {
				i--;
				std::cout << elem[i] << '\n';
			}
			while (i > 0);
		}
	};
	
	int main() {		
		int i = 0;
		int n = 0;
		
		double elem = 0.0;
		
		std::cout << "Введите количество элементов в стеке: ";
		std::cin >> n;

		Stack *stk = new Stack(NMAX);
		
		for(i = 0; i < n; i++) {
			std::cout << "Введите " << i << "-й элемент: ";
			std::cin >> elem;
			
			stk->push(elem);
		}
		
		std::cout << "В стеке " << stk->gettop() << " элементов." << '\n';
				
		stk->stkPrint();
		
		std::cout << "Верхний элемент " << stk->stkTop() << '\n';
		do {
			std::cout << "Извлекаем элемент " << stk->pop();
			std::cout << ". В стеке осталось " << stk->gettop() << " элементов." << '\n';
		} 
		while (stk->isempty() == 0);
		
		std::cout << '\n';
		return 0;
	}
