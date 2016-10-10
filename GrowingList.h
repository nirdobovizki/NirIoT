// GrowingList.h

#ifndef _GROWINGLIST_h
#define _GROWINGLIST_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

template <class T>
class GrowingList
{
private:
	T* m_buffer;
	int m_count;
	int m_size;

public:
	GrowingList()
	{
		m_buffer = NULL;
		m_count = 0;
		m_size = 0;
	}

	T& GetAt(int index)
	{
		return m_buffer[index];
	}
	
	void Add(const T& value)
	{
		if (m_count + 1 > m_size)
		{
			int newSize = m_size ? m_count + 2 : 3;
			T* newBuffer = (T*)malloc(newSize*sizeof(T));
			if (m_buffer != NULL)
			{
				memcpy(newBuffer, m_buffer, sizeof(T*)*m_count);
				free(m_buffer);
			}
			m_buffer = newBuffer;
			m_size = newSize;
		}
		m_buffer[m_count++] = value;
	}

	int GetCount()
	{
		return m_count;
	}
};


#endif

