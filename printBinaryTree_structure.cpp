#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <string>
#include <stack>
using namespace std;

int lg(double number){
	return log(number) / log(2);
}

void place_newline(int num){
	for (int i = 0; i < num - 1; i++)
		cout << "\n";
	return;
}

void place_space(int num){
	for (int i = 0; i < num; i++)
		cout << " ";
	return;
}

string add_spaces(int num){
	string str = "";
	for (int i = 0; i < num; i++)
		str += " ";
	return str;
}

bool is_power_of_two(int num){
	for (int next = 1; next <= num; next <<= 1)
	if (num == next)
		return true;
	return false;
}

void fit_string(vector <int> bfs_seq, int&limit){
	int next, dif;
	for (next = 1; next <= bfs_seq.size(); next <<= 1);
	dif = next - bfs_seq.size() - 1;
	cout << "limit = " << next << " nodes (max, in total)." << endl << endl;
	limit = next;
	for (int i = 0; i < dif; i++, bfs_seq.push_back(-1));
	return;
}

int print_tree(vector <int> bfs_seq){
	int count = 0, next = 1, limit = 0, size1, size2, *aux;
	string temp = "";
	stack <string> levels;
	//string str = "123450789010040";
	//string str = "1234507123400711234500000";
	//2_nodes..
	//string str = "1";
	//4_nodes..
	//string str = "123";
	//8_nodes..
	//string str = "1234567";
	//16_nodes..
	//string str = "123456712345678";
	//32_nodes..
	//string str = "1234567123456711234567891234567";
	//64_nodes..
	//string str = "123456712345671123456789123456712346712345671123456789123456789";
	//128_nodes..
	//string str = "1234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789";
	//256_nodes..
	//string str = "123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891";
	//512_nodes..
	//string str = "1234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678911234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912";
	//1024_nodes..
	//string str = "123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891212345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789112345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123";
	//2048_nodes..
	//string str = "1234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678911234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891231234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678911234567123456711234567891234567123456712345671123456789123456781234567123456711234567891234567123456712345671123456789123456789123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891123456712345671123456789123456712345671234567112345678912345678123456712345671123456789123456712345671234567112345678912345678912345671234567112345678912345671234567123456711234567891234567812345671234567112345678912345671234567123456711234567891234567891234";
	fit_string(bfs_seq, limit);
	//if(limit > desired_limit)
	//	return 0;
	//size1 = str.size()+limit/2;
	size1 = bfs_seq.size() + limit;
	size2 = size1 / 2;
	for (int i = 0; i < bfs_seq.size(); i++){
		if (count == next){
			count = 0;
			next <<= 1;
			size1 = size2;
			size2 /= 2;
			//aux = str.substr(next - 1, next);
			aux = new int[next];
			for (int i = 0; i < next; i++)
				aux[i] = bfs_seq[i + next - 1];
			for (int i = 0; i < next; i++){
				if (i == 0)
					temp += add_spaces(size2);
				if (aux[i] != -1 && i % 2 == 0)
					temp += "/" + add_spaces(size1);
				else if (aux[i] != -1 && i % 2 == 1)
					temp += "\\" + add_spaces(size1);
				if (aux[i] == -1)
					temp += add_spaces(size1 + 1);
			}
			if (next < limit >> 1){
				for (int i = 0; i < size2; i++){
					for (int j = 0; j < temp.size(); j++)
					if (temp[j] == '/'){
						temp[j + 1] = '/';
						temp[j] = ' ';
						j++;
					}
					else if (temp[j] == '\\'){
						temp[j - 1] = '\\';
						temp[j] = ' ';
						j++;
					}
					levels.push(temp);
				}
				cout << endl;
				for (; !levels.empty(); levels.pop()){
					cout << levels.top() << endl;
					//system("sleep .0625s");
				}
			}
			else{
				cout << endl << temp << endl;
				//system("sleep .0625s");
			}
			temp = "";
			delete[] aux;
		}

		if (count == 0)
			place_space(size2);
		else
			place_space(size1 - 1);
		if (bfs_seq[i] != -1)
			cout << bfs_seq[i];
		else
			cout << "  ";
		count++;
	}
	cout << endl << endl;
	return 0;
}

struct tree_el {
	int val;
	struct tree_el * right, *left;
};

typedef struct tree_el node;

void insert(node ** tree, node * item) {
	if (!(*tree)) {
		*tree = item;
		return;
	}
	if (item->val<(*tree)->val)
		insert(&(*tree)->left, item);
	else if (item->val>(*tree)->val)
		insert(&(*tree)->right, item);
}

void printout(node * tree) {
	if (tree->left) printout(tree->left);
	printf("%d\n", tree->val);
	if (tree->right) printout(tree->right);
}

void print_pre_order_sequence(node * ptr){
	if (ptr != NULL){
		cout << ptr->val << " ";
		print_pre_order_sequence(ptr->left);
		print_pre_order_sequence(ptr->right);
	}
	return;
}

void print_in_order_sequence(node * ptr){
	if (ptr != NULL){
		print_in_order_sequence(ptr->left);
		cout << ptr->val << " ";
		print_in_order_sequence(ptr->right);
	}
	return;
}

void print_post_order_sequence(node * ptr){
	if (ptr != NULL){
		print_post_order_sequence(ptr->left);
		print_post_order_sequence(ptr->right);
		cout << ptr->val << " ";
	}
	return;
}

void print_level_order_sequence(node * & ptr, queue <node *> & q, node * dummy, int&next, int&count, int&total, vector <int> & reserve){
	if (total == next){
		if (count == total)
			return;
		count = 0;
		total = 0;
		next <<= 1;
	}

	if (!q.empty()){
		if (ptr->val != -1){
			cout << ptr->val << " ";
			reserve.push_back(ptr->val);
		}
		else if (ptr->val == -1){
			//cout << "0 ";
			reserve.push_back(-1);
		}

		if (ptr->left){
			q.push(ptr->left);
			total++;
		}
		else{
			q.push(dummy);
			total++;
			count++;
		}

		if (ptr->right){
			q.push(ptr->right);
			total++;
		}
		else{
			q.push(dummy);
			count++;
			total++;
		};
		q.pop();
		print_level_order_sequence(q.front(), q, dummy, next, count, total, reserve);
		return;
	}
}

int main() {
	node * curr, *root;
	node * dummy = new node;
	dummy->val = -1;
	dummy->left = NULL;
	dummy->right = NULL;
	int i, next = 1, count = 0, total = 0, desired_limit = 64;
	vector <int> bfs_seq;
	queue <node *> reserve;
	root = NULL;
	srand(time(NULL));
	for (i = 1; i <= 32; i++) {
		curr = (node *)malloc(sizeof(node));
		curr->left = curr->right = NULL;
		curr->val = rand() % 100;
		//cout << endl <<"el valor insertado: "<<curr->val;
		insert(&root, curr);
	}
	system("clear");
	//printout(root);
	cout << "In order: " << endl;
	print_in_order_sequence(root);
	cout << endl << endl << "Pre order: " << endl;
	print_pre_order_sequence(root);
	cout << endl << endl << "Post order: " << endl;
	print_post_order_sequence(root);
	cout << endl << endl << "Level order: " << endl;
	reserve.push(root);
	next <<= 1;
	print_level_order_sequence(root, reserve, dummy, next, count, total, bfs_seq);
	cout << endl << endl;
	print_tree(bfs_seq);
	cout << endl << endl;
	system("PAUSE");
	return 0;
}