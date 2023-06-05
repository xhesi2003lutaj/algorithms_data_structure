#include<iostream>
#include<deque>
using namespace std;


class WindGauge {
		private:
				int period;
				int speed;
				deque<int>history;
		public:
				WindGauge(int period = 12);
				void currentWindSpeed(int newspeed);
				int highest() const;
				int lowest() const;
				int average() const ;
				int countels();
				void erase_els();
				void print();
				int returnsum();

};
