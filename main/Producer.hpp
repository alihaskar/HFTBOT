#include "binance-ws.hpp"
#include "binance-http.hpp" 
#include "ftx-http.hpp"
#include "ftx-ws.hpp"
#include "coinbase-ws.hpp"
#include "coinbase-http.hpp"
#include "kraken-http.hpp"
#include "kraken-ws.hpp"
#include <sstream>


void binance_producer_main(net::io_context& ioc, ssl::context& ctx,std::string &symbol);

void ftx_producer_main(net::io_context& ioc, ssl::context& ctx, std::string &symbol);

void kraken_producer_main(net::io_context& ioc, ssl::context& ctx, std::string &symbol);

void coinbase_producer_main(net::io_context& ioc, ssl::context& ctx, std::string &symbol);

