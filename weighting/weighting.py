import datetime
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

def load_days_weights(filepath, delim=','):
    dates, weights = [], []
    with open(filepath) as f:
        #f.readline()
        days, weights = np.loadtxt(f, unpack=True, delimiter = delim, skiprows=1,
                                   converters={0: mdates.strpdate2num('%m/%d/%Y')})
#         f.readline()
#         for line in f:
#             line = line.strip()
#             if not line:
#                 continue
#             date, weight = line.split(delim)
#             dates.append(datetime.datetime.strptime(date, '%m/%d/%Y').date())
#             weights.append(float(weight))
    return days, weights

def cmp_exp_weighted_moving_avg(date, days, weights, alpha=0.9):
    ## should memoize
    index = list(days).index(date)
    if index == 0:
        return weights[0]
    else:
        return alpha * weights[index] + \
            (1 - alpha) * cmp_exp_weighted_moving_avg(days[index - 1], days, weights, alpha)

if __name__ == '__main__':
    filepath = '/home/craigg/PER/weight_log.csv'
    days, weights = load_days_weights(filepath)
    base = datetime.datetime.today()
    avg_weights = []
    for date in days:
        avg_weights.append(cmp_exp_weighted_moving_avg(date, days, weights))
    print days

    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot_date(dates, opens, '-')
    ax.plot_date(days, avg_weights, 'rx', xdate=True, ydate=True)
    
# format the ticks
ax.xaxis.set_major_locator(years)
ax.xaxis.set_major_formatter(yearsFmt)
ax.xaxis.set_minor_locator(months)
ax.autoscale_view()

#     
#     plt.show()
