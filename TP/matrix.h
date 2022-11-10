typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} rgb_color;


void matrix_init();
void pulse_SCK();
void pulse_LAT();

void deactivate_rows();
void activate_row(int row);
void send_byte(uint8_t val, int bank);
void mat_set_row(int row, const rgb_color* val);
void init_bank0();

void test_pixels();
void image_statique();


#define RST_0 (GPIOC->BSRR = GPIO_BSRR_BR3)
#define RST_1 (GPIOC->BSRR = GPIO_BSRR_BS3)
#define SB_0 (GPIOC->BSRR = GPIO_BSRR_BR5)
#define SB_1 (GPIOC->BSRR = GPIO_BSRR_BS5)
#define LAT_0 (GPIOC->BSRR = GPIO_BSRR_BR4)
#define LAT_1 (GPIOC->BSRR = GPIO_BSRR_BS4)
#define SCK_0 (GPIOB->BSRR = GPIO_BSRR_BR1)
#define SCK_1 (GPIOB->BSRR = GPIO_BSRR_BS1)
#define SDA_0 (GPIOA->BSRR = GPIO_BSRR_BR4)
#define SDA_1 (GPIOA->BSRR = GPIO_BSRR_BS4)
#define ROW0_0 (GPIOB->BSRR = GPIO_BSRR_BR2)
#define ROW0_1 (GPIOB->BSRR = GPIO_BSRR_BS2)
#define ROW1_0 (GPIOA->BSRR = GPIO_BSRR_BR15)
#define ROW1_1 (GPIOA->BSRR = GPIO_BSRR_BS15)
#define ROW2_0 (GPIOA->BSRR = GPIO_BSRR_BR2)
#define ROW2_1 (GPIOA->BSRR = GPIO_BSRR_BS2)
#define ROW3_0 (GPIOA->BSRR = GPIO_BSRR_BR7)
#define ROW3_1 (GPIOA->BSRR = GPIO_BSRR_BS7)
#define ROW4_0 (GPIOA->BSRR = GPIO_BSRR_BR6)
#define ROW4_1 (GPIOA->BSRR = GPIO_BSRR_BS6)
#define ROW5_0 (GPIOA->BSRR = GPIO_BSRR_BR5)
#define ROW5_1 (GPIOA->BSRR = GPIO_BSRR_BS5)
#define ROW6_0 (GPIOB->BSRR = GPIO_BSRR_BR0)
#define ROW6_1 (GPIOB->BSRR = GPIO_BSRR_BS0)
#define ROW7_0 (GPIOA->BSRR = GPIO_BSRR_BR3)
#define ROW7_1 (GPIOA->BSRR = GPIO_BSRR_BS3)
