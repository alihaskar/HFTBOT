#include "Producer.hpp"

#include <boost/asio.hpp>

#include "Ringbuffer.hpp"
#include "types.hpp"

// FTX api order book data source.py : Hummingbot reference
// Producers putting data onto the respective queues.

void binance_producer_main(net::io_context &ioc, ssl::context &ctx, std::string &symbol, int &levels)
{
    SPSCQueue<OrderBookMessage> binance_producer_queue(1000);
    // auto binancews =
    // std::make_shared<binanceWS<price_level>>(ioc,ctx,binance_producer_queue);
    // // Subscribe diff messages
    auto binancews = std::make_shared<binanceWS>(boost::asio::make_strand(ioc), ctx, binance_producer_queue);
    // binanceWS<double> binancews(ioc,ctx,binance_producer_queue);
    binancews->subscribe_orderbook_diffs("SUBSCRIBE", symbol, levels);
    ioc.run();
}

void ftx_producer_main(net::io_context &ioc, ssl::context &ctx, std::string &symbol)
{
    SPSCQueue<OrderBookMessage> ftx_producer_queue(1000);
    auto ftxws = std::make_shared<ftxWS>(boost::asio::make_strand(ioc), ctx, ftx_producer_queue);
    // ftxWS<double> ftxws(ioc,ctx,ftx_producer_queue);
    ftxws->subscribe_orderbook_diffs("subscribe", symbol);

    ioc.run();
}

void coinbase_producer_main(net::io_context &ioc, ssl::context &ctx, std::string &symbol)
{
    SPSCQueue<OrderBookMessage> coinbase_producer_queue(1000);
    auto coinbasews = std::make_shared<coinbaseWS>(boost::asio::make_strand(ioc), ctx, coinbase_producer_queue);
    // coinbaseWS<double> coinbasews(ioc,ctx,coinbase_producer_queue);
    coinbasews->subscribe_orderbook_diffs("subscribe", symbol);
    ioc.run();
}

void kraken_producer_main(net::io_context &ioc, ssl::context &ctx, std::string &symbol, int &levels)
{
    SPSCQueue<OrderBookMessage> kraken_producer_queue(1000);
    auto krakenws = std::make_shared<krakenWS>(boost::asio::make_strand(ioc), ctx, kraken_producer_queue);
    // krakenWS<double> krakenws(ioc,ctx,kraken_producer_queue);
    krakenws->subscribe_orderbook_diffs("subscribe", symbol, 30);
    ioc.run();
}

// void bitfinex_producer_main(net::io_context& ioc, ssl::context& ctx,
// std::string &symbol, int &levels)
// {
//     SPSCQueue<OrderBookMessage>bitfinex_producer_queue(1000);
//     auto bitfinexws =
//     std::make_shared<krakenWS>(boost::asio::make_strand(ioc),ctx,bitfinex_producer_queue);
//     //krakenWS<double> krakenws(ioc,ctx,kraken_producer_queue);
//     bitfinexws->subscribe_orderbook_diffs("subscribe",symbol,30);
//     ioc.run();
// }
