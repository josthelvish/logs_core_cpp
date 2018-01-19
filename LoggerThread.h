//
// Created by jsilva on 04-01-2018.
//

#ifndef LOGS_CORE_CPP_LOGGERTHREAD_H

#include <iostream>
#include <cpprest/http_client.h>

#define LOGS_CORE_CPP_LOGGERTHREAD_H


using namespace web::http;
using namespace std;
using namespace web::http::client;          // HTTP client features


class LoggerThread {

public:


    void operator()(std::string URI){
        try {


            //Starting the request
            pplx::task<http_response> requestTask = getRequestHandler(URI);
//            requestTask.wait();

            http_response response = requestTask.get();

            cout << response.to_string() << endl;
                 cout << "############    LENGTH    \n\n" << endl;

            cout << response.headers().content_length() << endl;
            cout << "############    STATUS CODE    \n\n" << response.status_code() << endl;

            cout << endl;
            cout << "############    RESPONSE    \n\n" << response.to_string() << endl;
            cout << endl;
            //Prints Body
//            cout << response.extract_string().get() << endl;

        }catch (exception &exception){
            cout << "EXCEPTION: \n\n" << exception.what() << endl;
            cout << exception.what() << endl;
        }
    }


    virtual ~LoggerThread() = default;

    /**
     * Generic constructor.
     * Here are instantiated the SBQueue and launch the SBLogger thread.
     */
    LoggerThread(){};

private:

    pplx::task<web::http::http_response> getRequestHandler(utility::string_t URI){


        try {

            ucout << "Handler: "<< URI << std::endl;

            return pplx::create_task([URI]{
                http_client client(U(URI));

//                http_request request(methods::GET);
//                request.set_request_uri(U("v1/cleess/config/"));
//                request.headers().add(U("Authorization"),U("Bearer testToken"));
                ucout << "here it goes \n"<< std::endl;
                return client.request(methods::GET);})
                    .then([](http_response response){
                        ucout << "RESPONSE: \n"<< response.to_string() << std::endl;
                        return response;
                    });

            //If an exception is caught Creates a BAD REQUEST response
        }catch (std::exception &exception){
            ucout << "EXCEPTION on GET: "<< exception.what() << std::endl;
            [](http_response response){
                response.set_status_code(status_codes::BadRequest);
                return response;
            };

        }

    }
};
#endif //LOGS_CORE_CPP_LOGGERTHREAD_H
