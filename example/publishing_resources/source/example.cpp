/*
 * Example illustrating simple POST method handler.
 *
 * Server Usage:
 *    ./distribution/example/publishing_resources
 *
 * Client Usage:
 *    curl -v -X POST --data 'Hello, Restbed' 'http://localhost:1984/resource'
 */

#include <memory>
#include <cstdlib>
#include <restbed>

using namespace std;
using namespace restbed;
using namespace framework;

void post_method_handler( const shared_ptr< Session >& session )
{
    const auto request = session->get_request( );

    size_t content_length = 0;
    request->get_header( "Content-Length", content_length );

    session->fetch( content_length, [ request ]( const shared_ptr< Session >& session, const Bytes& body )
    {
        fprintf( stdout, "%.*s\n", ( int ) body.size( ), body.data( ) );

        session->close( OK, "Hello, World!", { { "Content-Length", "13" } } );
    } );
}

int main( const int, const char** )
{
    auto resource = make_shared< Resource >( );
    resource->set_path( "/resource" );
    resource->set_method_handler( "POST", &post_method_handler );

    auto settings = make_shared< Settings >( );
    settings->set_port( 1984 );
    settings->set_default_header( "Connection", "close" );

    Service service;
    service.publish( resource );
    service.start( settings );
    
    return EXIT_SUCCESS;
}
