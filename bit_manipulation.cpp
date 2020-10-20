ll sum_of_all_subset ( ll n){
    ll results[ ( 1 << n ) ] ;
    memset( results, 0, sizeof( results ) ) ;
    for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {
        for ( int j = 0; j < n ; ++ j ) {
            if ( ( i & ( 1 << j ) ) ! = 0 )
                results[i] += s [j] ;
        }
    }
}
