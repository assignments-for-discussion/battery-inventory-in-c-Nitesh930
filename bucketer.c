#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  
  for (int i = 0; i < nBatteries; ++i) {
    // Assuming rated capacity is 120 Ah for all batteries
    float rated_capacity = 120.0;
    float soh = (presentCapacities[i] / rated_capacity) * 100;
    //Checking for each Battery's soh and classifying them according given condition
    if (soh >= 80.0) {
      printf("For %d the classification is Healthy\n",presentCapacities[i]);
      counts.healthy++;
    } else if (soh >= 60.0) {
        printf("For %d the classification is Exchange\n",presentCapacities[i]);
      counts.exchange++;
    } else {
        printf("For %d the classification is Failed\n",presentCapacities[i]);
      counts.failed++;
    }
  }
  printf("The final classifications are :- \n");
  //Here we are checking and displaying for each classifications
  if(counts.healthy==2){
    printf("In Healthy we have %d numbers of batteries.\n",counts.healthy);
  }
  if(counts.exchange==3){
    printf("In Exchange we have %d numbers of batteries.\n ",counts.exchange);

  }
  if(counts.failed==1){
    printf("In Failed we have %d numbers of batteries.\n",counts.failed);
  }

  return counts;
}

void testBucketingByHealth() {
  const int presentCapacities[] = {113, 116, 80, 95, 92, 70};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  printf("--Counting Is Done--\n");
  assert(counts.healthy == 2);
  assert(counts.exchange == 3);
  assert(counts.failed == 1);
  
}

int main() {
  testBucketingByHealth();
  return 0;
}
