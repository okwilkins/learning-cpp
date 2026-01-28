#include <iostream>

struct AdStats {
    int adsWatched{};
    double pctUsersClickAd{};
    double avgEarningsPerClickedAd{};
};

void printAdStats(const AdStats &adStats) {
    const double totalDayRev{adStats.adsWatched * adStats.pctUsersClickAd *
                             adStats.avgEarningsPerClickedAd};

    std::cout << "Ads watched: " << adStats.adsWatched << '\n'
              << "Users that clicked ad: " << adStats.pctUsersClickAd << '\n'
              << "Average earning per clicked ad: £" << adStats.avgEarningsPerClickedAd << '\n'
              << "Total revenue for the day: £" << totalDayRev << '\n';
}

int main() {
    printAdStats(AdStats{
        .adsWatched = 100000,
        .pctUsersClickAd = 2.34234,
        .avgEarningsPerClickedAd = 0.01,
    });

    return 0;
}
