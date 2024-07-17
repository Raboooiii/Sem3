#include <iostream>
using namespace std ;

int partition ( int lower , int upper , int array[] ) 
{
	int pivot = array[ upper ] ;
	int j = lower - 1 ;

	for ( int i = lower ; i < upper ; i++ )
	{ 
		if ( array[ i ] < pivot )
		{
			j++ ;

			int temp ;
			
			temp = array[ i ] ;
			array[ i ] = array[ j ] ;
			array[j] = temp ;
			
			
		}
	}

		int temp2 ;
		
		temp2 = array[ j + 1 ] ;
		array[ j + 1 ] = array[ upper ] ;
		array[ upper ] = temp2 ;

	return (j+1) ;
}


void quickSort ( int lower , int upper , int array[] )
{
	if ( lower < upper )
	{
		int pivot1 = partition( lower , upper , array ) ;
	
		quickSort( lower , pivot1 - 1 , array  ) ;
		quickSort( pivot1 + 1 , upper , array ) ;
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
	
	quickSort( 0 , size , array ) ;

	cout << "Sorting... " << endl ;
	

	display( size , array ) ;

    return 0 ;
}

		
