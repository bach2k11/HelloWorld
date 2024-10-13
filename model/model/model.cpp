

#include <iostream>

using namespace std;
class Model {
public: long mComputer;
	int bQuantity;
	int sQuantity;
	float bPrice;
	float sPrice;
	double Profit;
	Model* next;
	Model() { next = NULL; }
	Model(long mComputer,	int bQuantity,	int sQuantity,	float bPrice,	float sPrice) {
		this->mComputer = mComputer; this->bQuantity = bQuantity; this->sQuantity = sQuantity; this->bPrice = bPrice; this->sPrice = sPrice; Profit = (sPrice - bPrice) * sQuantity;
	}
};
class QuanLy {
public :Model* head;
	QuanLy() { head = NULL; }
	void AddModel(long mC, int bQ, int sQ, float bP, float sP) {
		Model* newModel = new Model(mC, bQ, sQ, bP, sP);
		
		newModel->next = head;
		head = newModel;if (head == NULL) head = newModel;
	}
	void DeleteModel(long mC) {
		Model* rs = head;
		while (rs) {
			rs = rs->next;
			if (rs->next->mComputer == mC) {
				rs->next = rs->next->next;
				break;
			}
		}

	}
	double TienLai() {
		double tong = 0;
		Model* p = head;
		while (p) {
			tong += p->Profit;
			p = p->next;
		}
		return tong;
	}
	double GetProfit(long MS) {
		Model* p = head;
		while (p) {
			if (p->mComputer == MS)return p->Profit;
			p = p->next;
		}
		return 0;
	}
	void displayHighestProfitModels() {
		double maxProfit = -1;
		Model* p = head;
		while (p ) {
			if (p->Profit > maxProfit) {
				maxProfit = p->Profit;
			}
			p = p->next;
		}

		cout << "Highest Profit Models:\n";
		p = head;
		while (p) {
			if (p->Profit == maxProfit) {
				cout << "Model: " << p->mComputer << "\n";
				cout << "Profit: " << p->Profit << "\n";
			}
			p = p->next;
		}
	}
	
	Model* createSortedProfitList() {
		

		
		int size = 0;
		Model* p = head;
		while (p != NULL) {
			size++;
			p = p->next;
		}

		Model** nodeArray = new Model * [size];
		int index = 0;
		p = head;
		while (p != NULL) {
			nodeArray[index++] = p;
			p = p->next;
		}

		
		for (int i = 0; i < size - 1; ++i) {
			int maxIndex = i;
			for (int j = i + 1; j < size; ++j) {
				if (nodeArray[j]->Profit > nodeArray[maxIndex]->Profit) {
					maxIndex = j;
				}
			}
			if (maxIndex != i) {
				swap(nodeArray[i], nodeArray[maxIndex]);
			}
		}

		
		head = nodeArray[0];
		p = head;
		for (int i = 1; i < size; ++i) {
			p->next = nodeArray[i];
			p = p->next;
		}
		p->next = NULL;

		delete[] nodeArray;

		return head;
	}

};

int main()
{
	
		QuanLy store;

		store.AddModel(123456, 10, 5, 1000.0, 1500.0);
		store.AddModel(234567, 8, 6, 1200.0, 1800.0);
		store.AddModel(345678, 12, 8, 800.0, 1400.0);

		
		cout << "Total Profit: $"  << store.TienLai() << "\n\n";

		
		store.displayHighestProfitModels();

		
		store.createSortedProfitList();
		cout << "Sorted list by profit:\n";
		Model* p = store.head;
		while (p != nullptr) {
			cout << "Model: " << p->mComputer << ", Profit: $" << p->Profit << "\n";
			p = p->next;
		}

		return 0;
	}


