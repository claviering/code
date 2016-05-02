#include <stdio.h>
#include <string.h>

int  Count[ 6 ][ 27 ];
char Data[ 6 ];

void makelist( void )
{
    int i,j,k;
    memset( Count, 0, sizeof( Count ) );
    for ( i = 1 ; i <= 26 ; ++ i )
        Count[ 1 ][ i ] = 1;
    for ( i = 2 ; i <=  5 ; ++ i ) {
        for ( j =  1  ; j <= 26 ; ++ j )
        for ( k = j+1 ; k <= 26 ; ++ k )
            Count[ i ][ j ] += Count[ i-1 ][ k ]; 
    }
}

int calc( int s, int v, int L )
{
    int i,Sum = 0;
    for ( i = s+1 ; i < v ; ++ i )
        Sum += Count[ L ][ i ];
    return Sum;
}

int number( char ch )
{
    return ch-'a'+1;
}


bool legal( int L )
{
    for ( int i = 1 ; i < L ; ++ i )
        if ( Data[ i ] <= Data[ i-1 ] )
            return false;
    return true;
}

int main()
{
    makelist();
    while ( ~scanf("%s",&Data[ 1 ]) ) {
        int Len = strlen( &Data[ 1 ] );

        if ( legal( Len ) ) {
            int i,j,Sum = 1;

            Data[ 0 ] = 'a'-2;//补充循环边界
            for ( i = 1 ; i <= Len ; ++ i ) 
                Sum += calc( number( Data[ i-1 ] ), number( Data[ i ] ), Len-i+1 );

            for ( i = 1 ; i < Len ; ++ i )
            for ( j = 1 ; j <= 26 ; ++ j )
                Sum += Count[ i ][ j ];
            
            printf("%d\n",Sum);
        }else printf("0\n");
    }
    return 0;
}
