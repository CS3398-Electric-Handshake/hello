#include <seatest.h> 
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int count = 1;
    setlocale( LC_ALL, "" );
    bindtextdomain( "hello", "/usr/share/locale" );
    textdomain( "hello" );
    printf( gettext( "Hello, world!\n" ) );
    printf( ngettext( "Orangutan has %d banana.\n", "Orangutan has %d bananas.\n", count ), count );
    printf( gettext( "Try Weblate at <http://demo.weblate.org/>!\n" ) );
    printf( "%s\n", gettext( "Thank you for using Weblate." ) );
    exit(0);
}

void test_hello_world()
{
    char *s = "hello world!";
    assert_string_equal("hello world!", s);
    assert_string_contains("hello", s);
    assert_string_doesnt_contain("goodbye", s);
    assert_string_ends_with("!", s);
    assert_string_starts_with("hell", s);
}

void test_fixture_hello( void )
{
    test_fixture_start();      
    run_test(test_hello_world);   
    test_fixture_end();       
}


void all_tests( void )
{
    test_fixture_hello();   
}

int main( int argc, char** argv )
{
    run_tests(all_tests);   
    return 0;
}
