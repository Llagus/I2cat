package artery.application;

simple MyService like ItsG5Service
{
    parameters:
        bool par_is_there_emergency = default(false);
        bool par_is_there_speed = default(false);
}