package artery.application;

simple SystemMonitor
{
    parameters:
        double warmupTime = default(10);
        string outputFileName = default("output");

        @signal[numCamSent](type="long");
}
