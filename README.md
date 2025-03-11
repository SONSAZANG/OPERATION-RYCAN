# OPERATION - LYCAN 🎮  

## 📌 프로젝트 개요  
**OPERATION - LYCAN**은 TPS 기반 생존 슈팅 게임으로,  
바이러스가 퍼진 세계에서 **백신을 찾아 생존을 위해 전투를 펼치는 게임**입니다.  

- **개발 기간**: 2025.02.17 ~ 2025.03.06  
- **장르**: TPS 액션 슈팅  
- **플랫폼**: Windows PC (Unreal Engine 5)  
- **개발 인원**: 손은수, 지승현, 김세원, 신설빈  

### 🌍 **세계관**  
가까운 미래, **정체불명의 바이러스가 퍼지며 인류가 위기에 처한 세계**입니다.  
플레이어는 **특수부대 요원**으로 연구소에 투입되어  
**바이러스의 근원을 조사하고 백신을 확보하는 미션**을 수행합니다.  

---

## 시연 영상 및 PPT
[시연 PPT 링크](https://www.miricanvas.com/v/14axxoz)

[시연 영상 유튜브 링크](https://www.youtube.com/watch?v=nvhe9CZiGgs)

---

## 📌 팀원 소개 및 역할 분담  

| 이름 | 역할 | 주요 업무 |
|------|------|--------------------------------|
| **손은수 (팀장)** | 시스템 개발 | 프로젝트 리딩, 미션 시스템, 인벤토리, 인터랙션 기능, 레벨 스트리밍, 환경설정 기능 |
| **지승현** | 메인 캐릭터 | 캐릭터 애니메이션, 총기 시스템, 전투 및 UI, 크로스헤어, 사망 시스템 |
| **김세원** | 좀비 몬스터 | 좀비 AI, 관절별 피격 시스템, 몬스터 스폰 시스템, 1챕터 레벨 디자인 |
| **신설빈** | 보스 몬스터 | 보스 AI, 패턴 & 페이즈 전환, 시네마틱 제작, 보스 사운드 및 HP UI |

---

## 📌 게임 진행 흐름  

- **튜토리얼**: 기본 조작과 시스템 익히기  
- **1챕터**: 감염된 도심을 지나 연구소로 이동  
- **2챕터**: 연구소 내부 탐색 & 백신 회수  
- **보스전**: 최종 보스 "라이칸"과 전투  

---

## 📌 기능 구현 사항  
✔ **TPS 기반 전투 시스템**  
✔ **미션 시스템 & 인벤토리 구현**  
✔ **좀비 AI & 보스 AI (패턴 & 페이즈 전환 적용)**  
✔ **레벨 스트리밍을 활용한 맵 최적화**  
✔ **HUD 시스템 (체력, 스태미너, 총알, 감염 게이지 등)**  
✔ **시네마틱 연출 (보스 등장, 엔딩 크레딧)**  

---

## 📌 트러블 슈팅 (문제 해결 과정)  

**1️⃣ 레벨 스트리밍 최적화 문제** (담당: 손은수)  
**문제**: 고사양 배경 에셋으로 인해 **로딩 시 버벅임 발생**  
**해결**: 레벨 스트리밍 시스템 적용 & 미사용 에셋 최적화  

**2️⃣ 좀비 AI 동작 오류** (담당: 김세원)  
**문제**: BehaviorTree 실행 중 **좀비가 불규칙적으로 멈추는 현상 발생**  
**해결**: Task 종료 시 **Finish Execute(true)**를 명확히 적용하여 상태 전환 처리  

**3️⃣ 보스 시네마틱 제작 문제** (담당: 신설빈)  
**문제**: 레벨 스트리밍 이해 부족으로 **맵 설정이 변경될 위험 발생**  
**해결**: **MP4 영상 + Media Player 방식**으로 해결,  
추후 실시간 렌더링 방식으로 개선 예정  

**4️⃣ 캐릭터 애니메이션 상태 관리 문제** (담당: 지승현)  
**문제**: 애니메이션 전환 중 **예상치 못한 동작** 발생  
**해결**: **Trigger 수정 & TimeManager 활용**으로 상태 유지/해제 로직 보완  

---

## 🎬 **시연 영상**
🔗 [프로젝트 시연 영상 보기](https://youtu.be/nvhe9CZiGgs)  

---

## 📜 **사용 기술 스택**  
- **Unreal Engine 5** (게임 개발)  
- **Blueprint & C++** (게임 로직 및 AI 구현)  
- **Behavior Tree** (좀비 & 보스 AI)  
- **Niagara System** (이펙트 적용)  
- **UMG (Unreal Motion Graphics)** (UI 구현)  
- **레벨 스트리밍** (최적화 및 동적 로딩)  
- **GitHub** (버전 관리)  

---
