#include <stdio.h>
#include <stdbool.h>

struct Process
{
	int pid;
	int at;
	int bt;
	int ct, tt, wt, rt, st;
};

int main()
{
	int size = 0;
	printf("Enter number of processes: ");
	scanf("%d", &size);
	struct Process ps[size];

	printf("\nEnter process Details: \n");
	for (int i = 0; i < size; ++i)
	{
		printf("Enter %dth process details: \n", i + 1);
		ps[i].pid = i + 1;

		printf("\tEnter Arrival Time: ");
		scanf("%d", &ps[i].at);

		printf("\tEnter Burst Time: ");
		scanf("%d", &ps[i].bt);
	}

	printf("\n====================================================================================\n\n");
	printf("PID\tAT \t BT\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d \t %d \t %d \n", ps[i].pid, ps[i].at, ps[i].bt);
	}
	printf("\n\n====================================================================================\n\n");

	int n = size;
	int completed = 0;
	int currentTime = 0;
	int burstTimeR[4];
	bool iscompleted[4] = {false};

	float avgWT = 0, avgTT = 0, avgRT = 0;

	for (int i = 0; i < n; i++)
	{
		burstTimeR[i] = ps[i].bt;
	}

	while (completed != n)
	{

		int minimum = 99999;
		int miniI = -1;
		for (int i = 0; i < n; i++)
		{
			if ((ps[i].at <= currentTime) && (iscompleted[i] == false))
			{
				if (burstTimeR[i] < minimum)
				{
					minimum = burstTimeR[i];
					miniI = i;
				}
				if (burstTimeR[i] == minimum)
				{
					if (ps[i].at < ps[miniI].at)
					{
						minimum = burstTimeR[i];
						miniI = i;
					}
				}
			}
		}

		if (miniI == -1)
		{
			currentTime++;
		}
		else
		{

			if (burstTimeR[miniI] == ps[miniI].bt)
			{
				ps[miniI].st = currentTime;
			}

			burstTimeR[miniI] -= 1;
			currentTime++;

			if (burstTimeR[miniI] == 0)
			{

				ps[miniI].ct = currentTime;
				ps[miniI].tt = ps[miniI].ct - ps[miniI].at;
				ps[miniI].wt = ps[miniI].tt - ps[miniI].bt;
				ps[miniI].rt = ps[miniI].st - ps[miniI].at;

				avgWT += ps[miniI].wt;
				avgTT += ps[miniI].tt;
				avgRT += ps[miniI].rt;

				completed++;
				iscompleted[miniI] = true;
			}
		}
	}

	printf("PID \t AT \t BT \t CT \t TT \t WT \t RT \t\n");
	for (int i = 0; i < n; i++)
	{

		printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t\n", ps[i].pid, ps[i].at, ps[i].bt, ps[i].ct, ps[i].tt, ps[i].wt, ps[i].rt);
	}
	printf("\n\n====================================================================================\n");
	printf("\n\n AVG WT: %f", avgWT / n);
	printf("\n\n AVG TT: %f", avgTT / n);
	printf("\n\n AVG RT: %f", avgRT / n);
	printf("\n\n====================================================================================\n");
}