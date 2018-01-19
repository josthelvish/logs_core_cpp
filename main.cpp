#include <iostream>
#include <cpprest/http_client.h>
#include <thread>
#include "LoggerThread.h"




int main() {



//   /*OK*/ std::string newURI = "http://127.0.0.1/sampleHTTP/downloads/test_10.img";
//  /*OK*/  std::string newURI = "https://stackoverflow.com/questions/5725430/http-test-server-that-accepts-get-post-calls";
//  /*OK*/  std::string newURI = "http://www.mock-server.com/";




//    /*NOT OK*/std::string newURI = "http://microsoft.github.io/cpprestsdk/namespaces.html";


//    /*NOT OK*/std::string newURI = "https://192.168.13.141/v1/cleess/config/";
//    /*NOT OK*/std::string newURI = "https://c4s-api.streambolico.com/73746167696e67a/client/config/";



//    try{
//
//
//    LoggerThread logger;
//    std::thread thread1(&LoggerThread::operator(),logger,newURI);
//    if(thread1.joinable()){
//        thread1.join();
//    }
//
//    }catch (exception &e){
//        cerr << e.what() << endl;
//    }

//    std::cout << std::this_thread::get_id()<< std::endl;
//
//
//
//    http_client_config config;
//    config.set_validate_certificates(false);
//    http_client client(newURI,config);
//
//    http_request request;
//
//    try {
//
////        request.headers().add("Authorization","Bearer testToken");
////    request.headers().add("Authorization","Bearer 8fce7194-a67d-44fd-8284-c114a6a4d5b7-104978e7-e357-439a-9e21-690fa0558198");
//        request.set_method(methods::GET);
//
//        client.request(request).then([](http_response response) {
//
//            std::cout << std::this_thread::get_id()<< std::endl;
//
//            if(response.status_code() == status_codes::OK) {
//
////                std::cout << response.to_string() << std::endl;
////                auto body = response.extract_string().get();
////                std::cout << body << std::endl;
//                std::cout << "STATUS OK" << std::endl;
//                return;
//            }else{
//
////                std::cout << response.to_string() << std::endl;
//                std::cout << "STATUS NOT OK" << std::endl;
//
//                return;
//            }
//        }).wait();
//
//
//        std::cout << ""<<std::endl;
//
//
//    }catch (http_exception exception1){
//
//        std::cout << "Exception " << exception1.what() << std::endl;
//
//    }catch (exception e) {
//
//        std::cout << "Exception " << e.what() << std::endl;
//    }


    //NOTE ################### 19-1-2018



    std::string newURI("http://192.168.13.141:8080");
    web::http::client::http_client_config config;
    config.set_validate_certificates(false);

    web::http::client::http_client client(newURI,config);
    web::http::http_request request;

    try {

//        request.headers().add("Authorization","Bearer testToken");
//    request.headers().add("Authorization","Bearer 8fce7194-a67d-44fd-8284-c114a6a4d5b7-104978e7-e357-439a-9e21-690fa0558198");
        request.set_method(web::http::methods::GET);

        client.request(request).then([](web::http::http_response response) {

            std::cout << std::this_thread::get_id()<< std::endl;

            if(response.status_code() == web::http::status_codes::OK) {

                std::cout << response.to_string() << std::endl;
                auto body = response.extract_string().get();
                std::cout << body << std::endl;
                std::cout << "STATUS OK" << std::endl;
                return;
            }else{

                std::cout << response.to_string() << std::endl;
                std::cout << "STATUS NOT OK" << std::endl;

                return;
            }
        }).wait();



    }catch (web::http::http_exception exception){

        std::cout << "Exception " << exception.what() << std::endl;

    }


    return 0;
}