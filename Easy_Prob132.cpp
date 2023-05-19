/* Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following operations:
    record(timestamp): records a hit that happened at timestamp
    total(): returns the total number of hits recorded
    range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)

Follow-up: What if our system has limited memory? */

#include <iostream>

using namespace std;

static const int MAX_SIZE = 1024;

class HitCounter{
    protected :        
        float m_hitRegister[MAX_SIZE] ;
        int m_index = 0;
        int m_total = 0;

    public:
        // records a hit that happened at timestamp
        void record(float timestamp){
            m_total += 1;
            m_hitRegister[m_index] = timestamp;
            m_index = (m_index + 1)%MAX_SIZE;
        }

        // Returns the total number of hits recorded
        int total(){
            return m_total;
        }

        // Returns the number of hits that occured betweeen timsetamps lower and upper (inclusive)
        int range(float lower, float upper){
            int total = 0;
            int limit = min(m_total, MAX_SIZE);
            for (int i=0; i<limit; i++){
                float timestamp = m_hitRegister[i];
                if ((timestamp >= lower) && (timestamp <= upper)){
                    total += 1;
                }
            }
            return total;
        }
};

int main(int argc, char *argv[])
{
    // HitCounter hitCounter ;
    // cout << hitCounter.total() << endl; 
    // hitCounter.record(0.25);
    // cout << hitCounter.total() << endl;
    // hitCounter.record(0.60);
    // cout << hitCounter.range(0.0,0.50) << endl;
    // cout << hitCounter.range(0.0,1.0) << endl;
};