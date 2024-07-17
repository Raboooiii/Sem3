#include <iostream>
using namespace std ;

void selectionSort ( int length , int array[] )
{
	for ( int i = 0 ; i < length ; i++ )
	{
		int min = i ;

		for ( int j = i + 1 ; j < length ; j++ )
		{
			if ( array[j] < array[min] )
			{
				int temp ;
				
			temp = array[min] ;
			array[min] = array[i] ;
			array[i] = temp ;
			}
	
		}

		
	}
}

void display ( int size , int array[] )
{
	cout << "Elements: " << endl ;
	for ( int i = 0 ; i < size ; i++ )
	{
		cout << array[i] << " " ;
	}
}

int main ( )
{
	int size ;
	
	cout << "Enter size: " <<  endl ;
	cin >> size;
	
	int array[ size ] ;

	cout << "Enter elements: " << endl ;
	for ( int i = 0 ; i < size ; i++ )
	{
		cin >> array[i] ;
	}
	
	selectionSort(  size , array ) ;

	cout << "Sorting... " << endl ;
	

	display( size , array ) ;

    return 0 ;
}
				


