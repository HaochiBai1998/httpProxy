class request {
    virtual void handle() = 0;
}
class postRequest:request {
    virtual void handle();
}
class connectRequest:request {
    virtual void handle();
}
class getRequest:request {
    virtual void handle();
}