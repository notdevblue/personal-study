#include <math.h>

class queue
{
public:
    queue(const int& capacity)
    {
        m_capacity = capacity;
        m_arr = new int[m_capacity] { 0, };
        m_low = 0;
        m_high = 0;
    }
    ~queue()
    {
        delete[] m_arr;
    }

    void push(const int& element)
    {
        if (m_high == m_low)
        {
            return;
        }
        
        m_arr[m_high % m_capacity] = element;
        ++m_high;
    }

    int pop()
    {
        if (m_low == m_high)
        {
            return -1;
        }

        int element = m_arr[m_low % m_capacity];
        ++m_low;
        
        return element;
    }

private:
    int m_capacity;
    int* m_arr;
    int m_low;
    int m_high;
};
