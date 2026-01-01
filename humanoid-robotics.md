# Rangkuman video
<img width="600" alt="image" src="https://github.com/user-attachments/assets/4b23c344-90a8-4276-8b9e-277f47f1f761" />

### The FASTEST introduction to Reinforcement Learning on the internet
**Apa itu Reinforcement Learning (RL)?**
RL adalah bidang machine learning yang mengajarkan komputer/robot untuk melakukan tugas melalui trial and error, mirip cara manusia belajar - menggunakan reward positif dan negatif untuk memperkuat perilaku yang diinginkan.

**Konsep Dasar: Markov Decision Process (MDP)**
- Agent: Yang bisa Anda kontrol langsung (otak, pemain, mobil)
- Environment: Yang tidak bisa Anda kontrol langsung (anggota tubuh, jalan, peta)
- State: Informasi dari environment (posisi, kecepatan, visual)
- Action: Pengaruh agent ke environment (gerakan, keputusan)
- Reward: Sinyal numerik apakah action baik/buruk

### Evolusi Metode RL
**1. Monte Carlo**
Belajar dari episode lengkap
Menghitung return dengan menjumlahkan semua reward
Lambat karena harus menunggu episode selesai

**2. Temporal Difference (TD)**
Lebih efisien dengan belajar step-by-step
Varian: SARSA, Expected SARSA, Q-Learning (paling efisien)
Memecahkan masalah credit assignment (action mana yang benar-benar bagus)

**3. Deep Q Networks (DQN)**
Mengganti tabel dengan neural network
Memungkinkan continuous state (tak terbatas)
Masih terbatas pada discrete actions

**4. Policy Gradients**
Langsung mengoptimalkan probability distribution
Memungkinkan continuous actions (gerakan halus, bukan diskrit)
Metode Actor-Critic: Actor (policy) bertindak, Critic (value function) mengevaluasi
Contoh algoritma: PPO, SAC

### Kesimpulan
Reinforcement Learning adalah teknologi penting untuk membawa AI ke dunia fisik, tetapi masih memerlukan pengembangan signifikan dalam efisiensi, keandalan, dan pemahaman lingkungan sebelum robot bisa melakukan tugas sehari-hari seperti mengikat tali sepatu atau melipat baju.

