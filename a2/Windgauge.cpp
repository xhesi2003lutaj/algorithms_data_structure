#include "Windgauge.h"
//set period to your needs if you dont want the default 12
WindGauge::WindGauge(int nperiod){
		period=nperiod; 
}

void WindGauge::print(){
		deque<int>::iterator ix=history.begin();
		while (ix!=history.end())
		{
				cout<<*ix<<" ";

				ix++;
		}
		printf("\n");
}

int WindGauge::highest()const{
		int max=history[0];
		for(int i=0;i<history.size();i++){
				if(history[i]>max){
						max=history[i];
				}
		}
		return max;
}

int WindGauge::lowest()const{
		int min=history[0];
		for(int i=0;i<history.size();i++){
				if(history[i]<min){
						min=history[i];
				}
		}
		return min;
}

int WindGauge::average()const{
		int els=history.size();

		int sum=0;
		/* deque<int>::iterator in;
		   in=history.begin(); */
		for (int i=0;i<els;i++)
		{
				sum+=history[i];
				//in++;
		} 

		return (sum/els);
} 

void WindGauge::currentWindSpeed(int speed){
		deque<int>::iterator it;

		it=history.begin();

		it=history.insert(it,speed);//sum+=speed;
		if(history.size()>period){
				cout<<"Deque is full so I am erasing the previous data\n";
				//continue;
				erase_els();
				/* return; */
		}
}

int WindGauge::countels(){
		int count=0;
		deque<int>::iterator it=history.begin();
		while (it<history.end())
		{
				count++;
				it++;
		}
		return count;

}
//erase elements if the windgauge gets full
void WindGauge::erase_els(){
		int count=countels();
		if(count>period){
				//history.erase(history.begin(),history.begin()+(count-period));
				history.erase(history.end());

		}

}
