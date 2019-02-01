
	#include <iostream>
	#define NMAX 100
	
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
			delete [] elem;
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
		bool isempty() {
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
		int n = 0;
		int value = 0;
		Stack *stk = new Stack(NMAX);
				
		std::cout << "Введите число: ";
		std::cin >> value;
		
		std::cout << "Введите основание: ";
		std::cin >> n;
		
		do {
			stk->push(value % n);
			value = value / n;
		} 
		while(value > 0);
		
		do {
			std::cout << stk->pop();
		} 
		while(stk->isempty() == 0);
		
		std::cout << '\n';
		return 0;
	}
	
