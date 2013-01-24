import datetime
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

def load_days_weights(filepath, delim=','):
    dates, weights = [], []
    with open(filepath) as f:
        days, weights = np.loadtxt(f, unpack=True, delimiter = delim, skiprows=1,
                                   converters={0: mdates.strpdate2num('%m/%d/%Y')})
    return days, weights

def cmp_exp_weighted_moving_avg(date, days, weights, alpha=0.9):
    ## should memoize
    index = list(days).index(date)
    if index == 0:
        return weights[0]
    else:
        return alpha * weights[index] + \
            (1 - alpha) * cmp_exp_weighted_moving_avg(days[index - 1], days, weights, alpha)

def plot_day_view(days, weights, avg_weights):
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot_date(days, avg_weights, 'b-', xdate=True)
    for day, avg_weight, weight in zip(days, avg_weights, weights):
        ax.vlines(day, min(avg_weight, weight), max(avg_weight, weight), 'b', 'dotted')
    ax.plot_date(days, weights, 'rD', xdate=True)
    # Format the ticks
    major_locator = mdates.DayLocator()
    a_fmt = mdates.DateFormatter('%m/%d')
    ax.xaxis.set_major_locator(major_locator)
    ax.xaxis.set_major_formatter(a_fmt)
    ax.autoscale_view()
    plt.show()

if __name__ == '__main__':
    filepath = '/home/craigg/PER/weight_log.csv'
    days, weights = load_days_weights(filepath)
    avg_weights = []
    for date in days:
        avg_weights.append(cmp_exp_weighted_moving_avg(date, days, weights))
    plot_day_view(days, weights, avg_weights)
